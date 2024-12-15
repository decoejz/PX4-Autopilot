#!/bin/bash

RED="\033[0;31m" # Red color
GREEN="\033[0;32m" # Green color
BLUE="\033[0;34m" # Blue color
NC='\033[0m' # No color

# cmake='/opt/homebrew/bin/cmake'

echo "Which sign scheme would you like to use?"
echo -en "1. No signature (${BLUE}default${NC})\n2. RSA\n\nRes: "
read -r DES_SIGN

if [ "$DES_SIGN" == "2" ]
then
    export SIGN_TYPE=RSA
else
    export SIGN_TYPE=no_sign
fi

# Build project
make px4_sitl gz_x500

echo "To run code execute:"
echo
echo "./build/px4_sitl_default/bin/px4"


