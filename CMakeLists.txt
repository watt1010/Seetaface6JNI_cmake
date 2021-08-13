cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("Seetaface6JNI")
set(DEVICE centos)
add_subdirectory(FaceAntiSpoofingX6)
add_subdirectory(FaceBoxes)
add_subdirectory(FaceRecognizer6)
add_subdirectory(FaceTracker6)
add_subdirectory(Landmarker)
add_subdirectory(PoseEstimator6)
add_subdirectory(QualityAssessor3)
add_subdirectory(SeetaAgePredictor)
add_subdirectory(SeetaEyeStateDetector)
add_subdirectory(SeetaGenderPredictor)
add_subdirectory(SeetaMaskDetector)