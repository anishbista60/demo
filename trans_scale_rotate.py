import cv2
import numpy as np
import matplotlib.pyplot as plt

image =cv2.imread('index.jpeg')
image_mat=cv2.cvtColor(image,cv2. COLOR_BGR2RGB)

ht,wd,c=image.shape
center=(wd/2,ht/2)

trans=np.float32([[1,0,50],[0,1,50]])
scale=np.float32([[2,0,0],[0,2,0]])
rotate=cv2.getRotationMatrix2D(center,30,1)

image_t=cv2.warpAffine(image_mat,trans,(wd+50,ht+50))
image_s=cv2.warpAffine(image_mat,scale,(wd*2,ht*2))
image_r=cv2.warpAffine(image_mat,rotate,(wd,ht))

l_title=["original","translate","scale","rotate"]
l_var=[image_mat,image_t,image_s,image_r]

fig,axs=plt.subplots(1,4)

for i in range(4):
    axs[i].imshow(l_var[i])
    axs[i].set_title(l_title[i])
   
plt.show()
