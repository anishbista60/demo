import cv2
import numpy as np
import matplotlib.pyplot as plt

image =cv2.imread('index.jpeg')
image_mat=cv2.cvtColor(image,cv2. COLOR_BGR2RGB)
gray_image=cv2.cvtColor(image,cv2. COLOR_BGR2GRAY)

sobel_x=np.array([[-1,0,1],
                  [-2,0,2],
                  [-1,0,1]])
sobel_y=np.array([[-1,-2,-1],
                  [0,0,0],
                  [1,2,1]])

edges_x=cv2.filter2D(gray_image,-1,sobel_x)
edges_y=cv2.filter2D(gray_image,-1,sobel_y)
edges=cv2.addWeighted(edges_x,0.5,edges_y,0.5,0)

sobelx=cv2.Sobel(gray_image,cv2.CV_64F,1,0,ksize=5)
sobely=cv2.Sobel(gray_image,cv2.CV_64F,0,1,ksize=5)
texture=sobelx+sobely

l_var=[image_mat,edges,texture]
l_title=["Original","edge detection","texture extraction"]

fig,axs=plt.subplots(1,3)
for i in range(3):
    axs[i].imshow(l_var[i])
    axs[i].set_title(l_title[i])

plt.show()
