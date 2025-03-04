import cv2
import pytesseract
import numpy as np

# Load image
image_path = "screen.png"  # Adjust if needed
image = cv2.imread(image_path)

if image is None:
    print("Error: Image not found!")
    exit()

# Convert to grayscale for better OCR
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply thresholding to remove noise and improve OCR accuracy
_, thresh = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY_INV)

# Extract text using Tesseract
custom_config = r"--oem 3 --psm 6"  # Optimize for text blocks
text = pytesseract.image_to_string(thresh, config=custom_config)

# Print extracted text
print("Extracted Text:")
print(text)

# (Optional) Show processed image for debugging
cv2.imshow("Processed Image", thresh)
cv2.waitKey(0)
cv2.destroyAllWindows()
