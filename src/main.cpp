#include <stdint.h>
#include <iostream>
#include <opencv2/opencv.hpp>

/* <!-- {{{1 --> function declarations
 */
static void tutorial(void);

/** <!-- {{{1 --> @brief definition of OpenCV study function
 */
typedef void (*opencv_func_t)(void);

/** <!-- {{{1 --> @brief OpenCV Function Table
 */
static const opencv_func_t FUNC_TABLE[] = {
    tutorial,
};

/** <!-- {{{1 --> @brief OpenCV Tutorial
 */
static void tutorial(void)
{
    // open
    cv::Mat img1 = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img1.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }
    cv::Mat img2 = img1.clone();

    // paint left top in RED
    const int32_t width = img1.rows;
    const int32_t height = img1.cols;
    int32_t x, y;
    for (x = 0; x < (width / 2); x++) {
        for (y = 0; y < (height / 2); y++) {
            img1.at<cv::Vec3b>(y, x)[0] =   0;
            img1.at<cv::Vec3b>(y, x)[1] =   0;
            img1.at<cv::Vec3b>(y, x)[2] = 255;
        }
    }

    // swap R,B left top
    uint8_t r, b;
    for (x = 0; x < (width / 2); x++) {
        for (y = 0; y < (height / 2); y++) {
            b = img2.at<cv::Vec3b>(y, x)[0];
            r = img2.at<cv::Vec3b>(y, x)[2];
            img2.at<cv::Vec3b>(y, x)[0] = r;
            img2.at<cv::Vec3b>(y, x)[2] = b;
        }
    }

    // save image
    cv::imwrite("out.jpg", img2);

    // concat images
    const cv::Mat tmp[3] = {
        img1,
        cv::Mat(cv::Size(10, height), CV_8UC3, cv::Scalar(0, 0, 0)),
        img2,
    };
    cv::Mat disp;
    cv::hconcat(tmp, 3, disp);
    cv::imshow("Tutorial", disp);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief main function
 * @return result of main
 * @retval 0: success
 */
int main(int argc, const char** argv)
{
    if (argc < 2) {
        return -1;
    }

    // parse argument
    uint32_t n = 0;
    try {
        n = std::stoul(argv[1]);
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid argument: " << argv[1] << std::endl;
        return -2;
    } catch (const std::out_of_range& e) {
        std::cout << "out of range: " << argv[1] << std::endl;
        return -3;
    }

    if (n >= (sizeof(FUNC_TABLE) / sizeof(FUNC_TABLE[0]))) {
        return -4;
    }

    // call function
    FUNC_TABLE[n]();
    return 0;
}

// end of file {{{1
// vim:ft=cpp:et:nowrap:fdm=marker
