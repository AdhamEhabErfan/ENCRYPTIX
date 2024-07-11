#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  // Load Image
  Mat image;
  string imagePath;
  cout << "Enter the path of the image: ";
  cin >> imagePath;
  image = imread(imagePath);

  if (image.empty()) {
      cout << "Failed to load image." << endl;
      return -1;
  }

  // Display Image
  namedWindow("Original Image", WINDOW_AUTOSIZE);
  imshow("Original Image", image);

  // Image Filters
  Mat grayImage, blurredImage, sharpenedImage;
  cvtColor(image, grayImage, COLOR_BGR2GRAY);
  GaussianBlur(image, blurredImage, Size(5, 5), 0);
  Laplacian(image, sharpenedImage, CV_8U, 3);

  // Color Adjustment
  Mat adjustedImage;
  image.copyTo(adjustedImage);
  int brightness = 50, contrast = 50;
  cout << "Adjust brightness (0-100): ";
  cin >> brightness;
  cout << "Adjust contrast (0-100): ";
  cin >> contrast;
  adjustedImage.convertTo(adjustedImage, -1, contrast / 50.0, brightness - 50);

  // Crop and Resize
  Rect roi(100, 100, 300, 300);
  Mat croppedImage = image(roi);
  Mat resizedImage;
  resize(image, resizedImage, Size(400, 400));

  // Save Image
  imwrite("grayscale.jpg", grayImage);
  imwrite("blurred.jpg", blurredImage);
  imwrite("sharpened.jpg", sharpenedImage);
  imwrite("adjusted.jpg", adjustedImage);
  imwrite("cropped.jpg", croppedImage);
  imwrite("resized.jpg", resizedImage);

  // User Interface
  cout << "Image processing operations completed." << endl;
  cout << "Saved images: grayscale.jpg, blurred.jpg, sharpened.jpg, adjusted.jpg, cropped.jpg, resized.jpg" << endl;

  waitKey(0);
  destroyAllWindows();
  return 0;
}