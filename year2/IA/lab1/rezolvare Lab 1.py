# a)
images = []
for i in range(9):
  images.append(np.load(f'images/car_{i}.npy'))
images = np.array(images)

# b)
sum_pixels = np.sum(images)
print(sum_pixels)

# c)
sum_pixels_array = np.sum(images, axis=(1,2))
print(sum_pixels_array)

# d)
index_max = np.argmax(sum_pixels_array, axis=0)
print(index_max)

# e)
mean_image = np.mean(images, axis=0)
from skimage import io
io.imshow(mean_image.astype(np.uint8)) # petru a putea fi afisata
 # imaginea trebuie sa aiba
 # tipul unsigned int
io.show()

# f)
deviatie_standard = np.std(images)
print(deviatie_standard)

# g)
new_images = (images - mean_image) / deviatie_standard
#for i in range(9):
#  io.imshow(new_images[i].astype(np.uint8))
#  io.show()
  
# h)
new_new_images = new_images[:, 200:300, 300:400]
#for i in range(9):
#  print(new_new_images[i].shape)