#include <iostream>
#include <string>
#include <stdint.h>
#include <string.h>

int main()
{
    signed char c_array[] = "MYLEETCODECPLUSSTRING";
    uint32_t num_row = 4, len = sizeof(c_array) / sizeof(signed char);
    if (num_row < 2) {
        return -1;
    }
    // Z字型变换：将给定的数据，从上到下、从左至右进行排列
    // 时间复杂度：O(n)

    
    // 解析：以(0-n)+(n-0)循环排列，例如：
    /*
        数组："LEETCODEISHIRING"，转换后
        L   C   I   R
        E T O E S I I G
        E   D   H   N

        通过观察可以发现，循环周期是 2n - 2
    */
    uint32_t relt_01 = len / (2 * num_row - 2), relt_02 = len % (2 * num_row - 2);
    uint32_t units_z = (relt_02 == 0 ? relt_01 : relt_01 + 1);
    uint32_t num_line = (num_row - 2 + 1) * units_z;  // 变换后数组的列数
    char *c_result = new char[num_row * num_line];
    memset(c_result, ' ', sizeof(signed char) * (num_row * num_line));

    for (int i = 0, loop_inner = 0, u = 0; u < units_z; ++u) {
        // 0~ n - 1
        for (int j_increase = 0; j_increase < num_row && i < len; ++j_increase, ++i) {
            c_result[j_increase * num_line + loop_inner] = c_array[i];
        }

        // n - 2 ~ 1
        for (int j_decrease = num_row - 2; j_decrease > 0 && i < len; --j_decrease, ++i) {
            c_result[j_decrease * num_line + (++loop_inner)] = c_array[i];
        }
        ++loop_inner;
    }

    std::cout << "\n***************************" << std::endl;
    std::cout << "result(array):" << std::endl;
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_line; ++j) {
            std::cout << c_result[i * num_line + j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
