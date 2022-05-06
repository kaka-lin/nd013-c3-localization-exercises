#!/bin/bash

xhost +localhost
docker run --rm -it \
    -e DISPLAY=host.docker.internal:0 \
    -e QT_X11_NO_MITSHM=1 \
    -e QT_QUICK_BACKEND=software \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --volume="$PWD:/root/project" \
    kakalin/pcl:1.8.0
