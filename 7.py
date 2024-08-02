import cv2
import matplotlib.pyplot as plt
image=cv2.imread("fruit.jpg")
image_mat=cv2.cvtColor(image,cv2.COLOR_BGR2RGB)
plt.title("Original Image")
ht,wd,channels=image.shape
midx=wd//2
midy=ht//2
leftup=image_mat[:midy,:midx]
rightup=image_mat[:midy,midx:]
leftdown=image_mat[midy:,:midx]
rightdown=image_mat[midy:,midx:]
plt.axis("off")
plt.imshow(image_mat)
fig , axs=plt.subplots(2,2)
lst_var=[leftup,rightup,leftdown,rightdown]
lst_titles=["leftup","rightup","leftdown","rightdown"]
k=0
for i in range(2):
  for j in range(2):
    axs[i,j].imshow(lst_var[k])
    axs[i,j].axis("off")
    axs[i,j].set_title(lst_titles[k])
    k=k+1
plt.show()
