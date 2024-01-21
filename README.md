# Neo-PSP-CRF

This repository is a new implementation of the system elaborated in this paper: [Advances in Semantic Image Segmentation using Probabilistic Superpixel-based Dense Conditional Random Field](https://ieeexplore.ieee.org/document/8314143/), shortened as Neo-PSP-CRF. To grasp the core concept quickly, please read the paper's abstract.

## How to execute this code

(1) Image processing is a key requirement of this project, so **openCV** needs to be installed first. Overall project management is done using Cmake.

(2) Download the code, extract it and navigate to the root directory of the project. The main.cpp is the core file and is dependent on some utility functions. Hence, compilation of some static library files is required.

(3) Navigate to the cnpy-master directory in src, where you need to obtain **libcnpy.a** using CMakeList.txt. It is used for reading Probability files of CNN into the memory to improve read speeds. The libcnpy.a file can be found in the build directory.

(4) In the densecrf_lib directory, obtain **libdensecrf.a** using CMakeList.txt, this function is used for the CRF A