#!/usr/bin/env bash
n=$1
folder=/afs/psi.ch/project/hedpc/raw_data/2013/ccdfli/2013.03.21/S00000-00999/
./bin/make_root $folder/S000$n
shift
python python/convert_images.py $folder/S000$n.root --format tif "$*"
