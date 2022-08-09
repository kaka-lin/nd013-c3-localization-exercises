// Udacity C3 Localization
// Dec 21 2020
// Aaron Brown

using namespace std;

#include <string>
#include <sstream>
#include "helper.h"

#include <pcl/registration/icp.h>
#include <pcl/console/time.h>   // TicToc

// Eigen::Matrix4d transform = ICP(map(target), scan(source), location, 50);
Eigen::Matrix4d ICP(PointCloudT::Ptr target, PointCloudT::Ptr source, Pose startingPose, int iterations) {
	Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity();

	//TODO: complete the ICP function and return the correct ed transform
  //Part1: Completed ICP function, increase iterations

  // 1. Convert starting pose to transformation matrix
  Eigen::Matrix4d initTransform = transform2D(startingPose.theta, startingPose.position.x, startingPose.position.y);

  // 2. Transform Source by starting pose (pose offset)
  //   pcl::transformPointCloud (#INPUT, #OUTPUT, #TRANSFORM);
  //     #INPUT `pcl::PointCloud<pcl::PointXYZ>` input point cloud
  //     #OUTPUT `pcl::PointCloud<pcl::PointXYZ>` output point cloud
  //     #TRANSFORM `Eigen::Matrix4d` transformation matrix
  PointCloudT::Ptr transformSource(new PointCloudT);
  pcl::transformPointCloud(*source, *transformSource, initTransform);

  // 3. Creating PCL ICP and setting ICP Hyper-parameters
  pcl::console::TicToc time;
  time.tic();
  pcl::IterativeClosestPoint<PointT, PointT> icp;
  icp.setMaximumIterations(iterations);
  icp.setInputSource(transformSource);
  icp.setInputTarget(target);

  // 4. Transform Source, Target, iterations, then align to get transform
  PointCloudT::Ptr cloud_icp(new PointCloudT);  // ICP output point cloud
  icp.align(*cloud_icp); // call align on the icp object

  // If icp converged get the icp objects output transform
  // and adjust it by the startingPose, return the adjusted transform
  if (icp.hasConverged()) {
  	std::cout << "\nICP has converged, score is " << icp.getFitnessScore() << std::endl;
  	transformation_matrix = icp.getFinalTransformation().cast<double>();
  	// 5. Multiply the transform with starting pose
    transformation_matrix =  transformation_matrix * initTransform;
  	return transformation_matrix;
  }

  // If icp did not converge log the message and return original identity matrix
  cout << "WARNING: ICP did not converge" << endl;
	return transformation_matrix;
}

int main() {
  pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("2D Viewer"));
	viewer->setBackgroundColor(0, 0, 0);
	viewer->addCoordinateSystem(1.0);

	// create a room: width:10, height:10
	double lowerX = -5;
	double upperX = 5;
	double lowerY = -5;
	double upperY = 5;

	vector<LineSegment> room;
	LineSegment top(0, 1, upperY, lowerX, upperX);
	room.push_back(top);
	LineSegment bottom(0, 1, lowerY, lowerX, upperX);
	room.push_back(bottom);
	LineSegment right(1, 0, upperX, lowerY, upperY);
	room.push_back(right);
	LineSegment left(1, 0, lowerX, lowerY, upperY);
	room.push_back(left);

	// create lidar
  // -> location(0, 0), orientation: 0
  // -> max range: 100, resolution: 128
	Lidar lidar(0, 0, 0, 100, 128);

  // get map of room (*target/reference)
	PointCloudT::Ptr map = lidar.scan(room);
	cout << "map captured " << map->points.size() << " points" << endl;
  renderPointCloud(viewer, map, "map", Color(0,0,1)); // render map

  // starting location
	PointCloudT::Ptr poses(new PointCloudT); 	// ground truth
	PointCloudT::Ptr locator(new PointCloudT); // estimated locations

	poses->points.push_back(PointT(lidar.x, lidar.y, 0));
	locator->points.push_back(PointT(lidar.x, lidar.y, 0));

  //////////////////////////////////////////////////////////////////
	// Move around the room

	// Part 1. Localize from single step
	vector<Vect2> movement = {Vect2(0.5, pi/3)};

	// Part 2. TODO: localize after several steps
	if(true) { // Change to true
		movement.push_back(Vect2(0.8, pi/10));
		movement.push_back(Vect2(1.0, pi/6));
	}

	// Part 3. TODO: localize after randomly moving around the whole room
	if(true) { // Change to true
		srand(time(0));
		for (int i = 0; i < 10; i++) {
		  double mag = 0.5 * ((double) rand() / (RAND_MAX)) + 0.5;
			double angle = pi/8 * ((double) rand() / (RAND_MAX)) + pi/8;
			movement.push_back(Vect2(mag, angle));
		}
	}

  // create starting pose
	Pose location(Point(0,0), 0);
	PointCloudT::Ptr scan; // source
	int count = 0;
	for (Vect2 move : movement) {
		// execute move
		lidar.Move(move.mag, move.theta);
		poses->points.push_back(PointT(lidar.x, lidar.y, 0));

		// scan the room (source)
		scan = lidar.scan(room);
		cout << "scan captured " << scan->points.size() << " points" << endl;
		renderPointCloud(viewer, scan, "scan_"+to_string(count), Color(1,0,0)); // render scan

		// perform localization
    // TODO: make the iteration count greater than zero
		Eigen::Matrix4d transform = ICP(map, scan, location, 50);
		Pose estimate = getPose(transform);

		// Save estimate location and use it as starting pose for ICP next time
    location = estimate;
		locator->points.push_back(PointT(estimate.position.x, estimate.position.y, 0));

		// Perform the transformation on the scan using transform from ICP
		PointCloudT::Ptr transformed_scan(new PointCloudT);
  	pcl::transformPointCloud(*scan, *transformed_scan, transform);
    // view transformed scan
    renderPointCloud(viewer, transformed_scan, "icp_scan_"+to_string(count), Color(0,1,0));

		count++;
	}

	// display ground truth poses vs estimated pose
	renderPointCloud(viewer, poses, "poses", Color(0,1,0), 8);
	renderPath(viewer, poses, "posePath", Color(0,1,0) );
	renderPointCloud(viewer, locator, "locator", Color(0,0,1), 5);
	renderPath(viewer, locator, "locPath", Color(0,0,1) );

	while (!viewer->wasStopped ()) {
		viewer->spinOnce ();
	}

	return 0;
}
