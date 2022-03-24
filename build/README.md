# Instructions

## Requirements

- C++
- [CMake](https://cmake.org/install/)
- [CARLA simulator](https://carla.org/)
- [PCL](https://github.com/PointCloudLibrary/pcl) (Point Cloud Library)
- [Eigen Library for C++](https://eigen.tuxfamily.org/index.php?title=Main_Page)

## Build
Build the image with:
```
docker build -t project4-dev -f Dockerfile .
```

Create a container with:
```
docker run --gpus all -v <PATH TO LOCAL PROJECT FOLDER>:/app/project/ --network=host -ti project4-dev bash
```
and any other flag you find useful to your system (eg, `--shm-size`).

## Updating the instructions

Feel free to submit PRs or issues should you see a scope for improvement.
