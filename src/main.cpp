#include <stdint.h>
#include <iostream>
#include <opencv2/opencv.hpp>

/* <!-- {{{1 --> function declarations
 */
static void tutorial(void);
static void answer001(void);
static void answer002(void);
static void answer003(void);
static void answer004(void);
static void answer005(void);
static void answer006(void);
static void answer007(void);

/** <!-- {{{1 --> @brief definition of OpenCV study function
 */
typedef void (*opencv_func_t)(void);

/** <!-- {{{1 --> @brief OpenCV Function Table
 */
static const opencv_func_t FUNC_TABLE[] = {
    tutorial,
    answer001,
    answer002,
    answer003,
    answer004,
    answer005,
    answer006,
    answer007,
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

/** <!-- {{{1 --> @brief Answer of Question 001
 */
static void answer001(void)
{
    // open
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    // swap Red / Blue
    const int32_t width = img.rows;
    const int32_t height = img.cols;
    int32_t x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint8_t b = img.at<cv::Vec3b>(y, x)[0];
            img.at<cv::Vec3b>(y, x)[0] = img.at<cv::Vec3b>(y, x)[2];
            img.at<cv::Vec3b>(y, x)[2] = b;
        }
    }
    cv::imshow("Answer001", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 002
 */
static void answer002(void)
{
    // open
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    // Grayscale
    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(width, height, CV_8UC1);
    int32_t x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint8_t b = img.at<cv::Vec3b>(y, x)[0];
            uint8_t g = img.at<cv::Vec3b>(y, x)[1];
            uint8_t r = img.at<cv::Vec3b>(y, x)[2];
            out.at<uint8_t>(y, x) = (uint8_t)(
                0.2126 * (float)r + 0.7152 * (float)g + 0.0722 * (float)b);
        }
    }
    cv::imshow("Answer002", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 003
 */
static void answer003(void)
{
    // open
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    // Binarization
    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(width, height, CV_8UC1);
    int32_t x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint8_t b = img.at<cv::Vec3b>(y, x)[0];
            uint8_t g = img.at<cv::Vec3b>(y, x)[1];
            uint8_t r = img.at<cv::Vec3b>(y, x)[2];
            uint8_t v = (uint8_t)(
                0.2126 * (float)r + 0.7152 * (float)g + 0.0722 * (float)b);
            out.at<uint8_t>(y, x) = (uint8_t)((v < 128) ? 0: 255);
        }
    }
    cv::imshow("Answer003", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 004
 */
static void answer004(void)
{
    // open
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    // Grayscale
    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(width, height, CV_8UC1);
    int32_t x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint8_t b = img.at<cv::Vec3b>(y, x)[0];
            uint8_t g = img.at<cv::Vec3b>(y, x)[1];
            uint8_t r = img.at<cv::Vec3b>(y, x)[2];
            out.at<uint8_t>(y, x) = (uint8_t)(
                0.2126 * (float)r + 0.7152 * (float)g + 0.0722 * (float)b);
        }
    }

    // Otsu's Binarization method
    int32_t th = 0;
    float max_sb = 0.0f;
    for (int32_t t = 0; t < 255; t++) {
        int32_t w0 = 0;
        int32_t w1 = 0;
        float m0 = 0.0f;
        float m1 = 0.0f;

        for (x = 0; x < width; x++) {
            for (y = 0; y < height; y++) {
                int32_t v = (int32_t)(out.at<uint8_t>(y, x));
                if (v < t) {
                    w0++;
                    m0 += (float)v;
                } else {
                    w1++;
                    m1 += (float)v;
                }
            }
        }

        m0 /= (float)w0;
        m1 /= (float)w1;
        float sb = (
            ((float)w0 / (float)(width * height)) *
            ((float)w1 / (float)(width * height)) *
            (m0 - m1) * (m0 - m1));
        if (sb > max_sb) {
            max_sb = sb;
            th = t;
        }
    }
    std::cout << "threshold = " << th << std::endl;

    // Binarization
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            uint8_t v = (uint8_t)out.at<uint8_t>(y, x);
            out.at<uint8_t>(y, x) = (uint8_t)((v < th) ? 0: 255);
        }
    }
    cv::imshow("Answer004", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 005
 */
static void answer005(void)
{
    // open
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    // RGB to HSV to RGB
    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(width, height, CV_8UC3);
    int32_t x, y;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            float b = (float)img.at<cv::Vec3b>(y, x)[0] / 255.0f;
            float g = (float)img.at<cv::Vec3b>(y, x)[1] / 255.0f;
            float r = (float)img.at<cv::Vec3b>(y, x)[2] / 255.0f;
            float c_max = fmax(r, fmax(g, b));
            float c_min = fmin(r, fmin(g, b));

            // RGB to HSV
            float h = 0.0f;
            if (c_max == c_min) {
                ;
            } else if (c_min == b) {
                h = 60.0f * (g - r) / (c_max - c_min) +  60.0f;
            } else if (c_min == r) {
                h = 60.0f * (b - g) / (c_max - c_min) + 180.0f;
            } else if (c_min == g) {
                h = 60.0f * (r - b) / (c_max - c_min) + 300.0f;
            }
            float v = c_max;
            float s = c_max - c_min;

            // invert Hue
            h = fmod((h + 180.0f), 360);

            // HSV to RGB
            float cc = s;
            float hh = h / 60.0f;
            float xx = cc * (1.0f - fabs(fmod(hh, 2) - 1.0f));
            r = g = b = (v - cc);
            if (hh < 1.0f) {
                r += cc;
                g += xx;
            } else if (hh < 2.0f) {
                r += xx;
                g += cc;
            } else if (hh < 3.0f) {
                g += cc;
                b += xx;
            } else if (hh < 4.0f) {
                g += xx;
                b += cc;
            } else if (hh < 5.0f) {
                r += xx;
                b += cc;
            } else if (hh < 6.0f) {
                r += cc;
                b += xx;
            }
            out.at<cv::Vec3b>(y, x)[0] = (uint8_t)(b * 255);
            out.at<cv::Vec3b>(y, x)[1] = (uint8_t)(g * 255);
            out.at<cv::Vec3b>(y, x)[2] = (uint8_t)(r * 255);
        }
    }
    cv::imshow("Answer005", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 006
 */
static void answer006(void)
{
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    int32_t x, y, c;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            for (c = 0; c < 3; c++) {
                uint8_t v = img.at<cv::Vec3b>(y, x)[c];
                v = 32 + 64 * ((v >> 6) & 0x03);
                out.at<cv::Vec3b>(y, x)[c] = v;
            }
        }
    }
    cv::imshow("Answer006", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

/** <!-- {{{1 --> @brief Answer of Question 7
 */
static void answer007(void)
{
    cv::Mat img = cv::imread(RESOURCE_DIR "imori.jpg", cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    const int32_t width = img.rows;
    const int32_t height = img.cols;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);
    int32_t ix, iy, x, y, c;
    const int32_t r = 8;
    for (ix = 0; ix < width; ix+= r) {
        for (iy = 0; iy < height; iy += r) {
            for (c = 0; c < 3; c++) {
                uint32_t v = 0;
                for (x = 0; x < r; x++) {
                    for (y = 0; y < r; y++) {
                        v += img.at<cv::Vec3b>(y + iy, x + ix)[c];
                    }
                }
                v >>= 6;
                for (x = 0; x < r; x++) {
                    for (y = 0; y < r; y++) {
                        out.at<cv::Vec3b>(y + iy, x + ix)[c] = (uint8_t)v;
                    }
                }
            }
        }
    }
    cv::imshow("Answer007", out);
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
