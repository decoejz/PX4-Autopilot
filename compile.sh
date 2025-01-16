#!/bin/bash

echo "Build from zero?"
echo -en "Res (y|N): "
read -r BUILDING_POINT

if [ "$BUILDING_POINT" == "y" ]
then

    rm -rf build/

fi

# Build project
make px4_sitl gz_x500

# echo "To run code execute:"
# echo
# echo "./build/px4_sitl_default/bin/px4"


