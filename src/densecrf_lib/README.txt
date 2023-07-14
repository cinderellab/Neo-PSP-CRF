DenseCRF - Code
=============
http://graphics.stanford.edu/projects/densecrf/

This software pertains to the research described in the NIPS 2011 paper:
Efficient Inference in Fully Connected CRFs with Gaussian Edge Potentials, by
Philipp Krähenbühl and Vladlen Koltun
If you're using this code in a publication, please cite our paper.

This software is provided for research purposes, with absolutely no warranty
or suggested support, and use of it most follow the BSD license agreement, at
the top of each source file. *Please do not contact the authors for assistance
with installing, understanding or running the code.* However if you think you
have found an interesting bug, the authors would be grateful if you could pass
on the information.


How to compile the code
-----------------------
Dependencies:
 * cmake  http://www.cmake.org/

Linux, Mac OS X and Windows (cygwin):
 mkdir build
 cd build
 cmake -D CMAKE_BUILD_TYPE=Release ..
 make
 cd ..

Windows
 You're probably better off just copying all files into a Visual Studio
 project


How to run the example
----------------------
An example on how to use the DenseCRF can be found in
examples/dense_inference.cpp. The example loads an image and some annotation