# LBYARCH-x86-to-C-Interface-Project
### ***made by DON LAUDE A. ASPECTO & GHRAZIELLE REI A. DE RAMOS***

- This is a project requirement for the course subject LBYARCH on De La Salle University - Manila. 
- This project is built using Visual Studio Community & NASM
- This project is made with C and Assembly languages.
- The project specifications are as follows: ![Project Specifications](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/assets/74148315/fb3e0d99-7211-4e18-b85c-1f4034abf075)


## The Program in a Nutshell
For this project, the kernel of the cFunction.c is called from main.c to calculate the result for each element of arrays X, Y, and Z, using a scalar A as a multiplier. On the other hand, assemblyFunction.asm is an assembly file that contains the function zoperation1 that performs the same kernel computation done by cFunction.c while using SIMD instructions (mulsd and addsd) to process multiple data elements simultaneously.

The assembly kernel zoperation1 directly handles the multiplication and addition operations using SIMD instructions, which can lead to better performance compared to the C kernel, especially when processing large arrays due to the ability to perform operations on multiple elements in parallel. The cFunction, being written in C, may have slightly higher overhead due to its scalar nature and the function call mechanism.

## ANALYSIS OF EXECUTION TIMES 
Based on the screenshots provided and organized below, we can observe that the C kernel outperforms the assembly kernel, especially for larger input sizes. For example, at 2^28 elements, the C kernel takes around 1112.1667ms, while the assembly kernel takes approximately 1554.5000ms in Release mode. This indicates a noticeable difference in favor of the C implementation. 

### DEBUG - Average Execution Times
2^20 | 2^24 | 2^28
:-------------------------:|:-------------------------:|:-------------------------:
![2^20 Debug](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E20%20Debug.png)  |  ![2^24 Debug](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E24%20Debug.png) |  ![2^28 Debug](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E28%20Debug.png)

However, for smaller input sizes, such as 2^20 and 2^24 elements, the performance gap between the two kernels is smaller, with the assembly kernel showing slightly higher execution times. This suggests that the choice between C and Assembly language may depend on the specific requirements of the application, with the C kernel providing better overall performance but the assembly kernel potentially offering optimizations in certain scenarios. 

### RELEASE - Average Execution Times
2^20 | 2^24 | 2^28
:-------------------------:|:-------------------------:|:-------------------------:
![2^20 Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E20%20Release.png)  |  ![2^24 Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E24%20Release.png) |  ![2^28 Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E28%20Release.png)

Meanwhile, in comparison of the Debug and Release modes, it is undeniable on how the latter is significantly faster than the prior. The Debug mode introduces additional overhead, significantly increasing the execution times for both kernels. Despite this, the relative performance difference between the C and Assembly kernels remains consistent, with the C kernel generally performing better. This implies that while debugging introduces overhead, the impact on the relative performance of the two kernels is minimal, maintaining the trend observed in Release mode.

## Sample of Incorrect Output (Release)
Previous screenshots were all correct outputs according to the correctness checker within the code. Therefore, provided below are sample screenshots in the case that the output of one kernel is wrong *(does not match with the output of the other kernel)*. 

Please note that the error was manually produced by changing the output value of the 3rd index from the Assembly Kernel output _(e.g. asmZ[3] = 99.99)_.
*These screenshots were taken from Release mode.*
2^20 | 2^24 | 2^28
:-------------------------:|:-------------------------:|:-------------------------:
![2^20 Incorrect Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E20%20Incorrect%20Release.png)  |  ![2^24 Incorrect Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E24%20Incorrect%20Release.png) |  ![2^28 Incorrect Release](https://github.com/ghrayshell/LBYARCH-x86-to-C-Interface-Project/blob/cdf8d5108bf5c2fea312b2ef0417409773af6f8b/Screenshots%20of%20Program%20Output/2%5E28%20Incorrect%20Release.png)
