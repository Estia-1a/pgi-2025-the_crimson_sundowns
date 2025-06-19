# Daily Evaluation 19/06 - 21:07:53
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 20/23 :  86%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                           | Stdout   |
| :---------- | :---------- | :------------------------------------------------------------------------------------- | :------- |
| dimension   | 4/4 :  100% |                                                                                        |          |
| first_pixel | 5/5 :  100% |                                                                                        |          |
| tenth_pixel | 2/5 :  40%  | Tenth Pixel Red : 255,0,0<br>Tenth Pixel Green : 0,255,0<br>Tenth Pixel Blue : 0,0,255 | <br><br> |
| second_line | 5/5 :  100% |                                                                                        |          |
| print_pixel | 4/4 :  100% |                                                                                        |          |

# Milestone  statistiques
Score : 18/26 :  69%
## Detail by Feature
| Feature         | Score      | Missed tests                 | Stdout                            |
| :-------------- | :--------- | :--------------------------- | :-------------------------------- |
| max_pixel       | 3/4 :  75% | Max Pixel black 8x8          | max_pixel (1512682712, 32766): 0… |
| min_pixel       | 3/4 :  75% | Min Pixel white 8x8          | min_pixel (-514105896, 32766): 0… |
| min_component R | 2/3 :  66% | Min Component R of white 8x8 | min_component R (6, 0): 255       |
| min_component G | 2/3 :  66% | Min Component G of white 8x8 | min_component G (6, 0): 255       |
| min_component B | 2/3 :  66% | Min Component B of white 8x8 | min_component B (6, 0): 255       |
| max_component R | 2/3 :  66% | Max Component R of black 8x8 | max_component R (6, 0): 0         |
| max_component G | 2/3 :  66% | Max Component G of black 8x8 | max_component G (6, 0): 0         |
| max_component B | 2/3 :  66% | Max Component B of black 8x8 | max_component B (6, 0): 0         |

# Milestone  colors
Score : 25/35 :  71%
## Detail by Feature
| Feature              | Score       | Missed tests                                                                                                                                         | Stdout                            |
| :------------------- | :---------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| color_red            | 0/5 :  0%   | Convert red image to RED<br>Convert blue image to RED<br>Convert green Image to RED<br>Convert white Image to RED<br>convert black Image to RED      | Image transformee enregistree da… |
| color_blue           | 5/5 :  100% |                                                                                                                                                      |                                   |
| color_green          | 5/5 :  100% |                                                                                                                                                      |                                   |
| color_gray           | 5/5 :  100% |                                                                                                                                                      |                                   |
| color_invert         | 5/5 :  100% |                                                                                                                                                      |                                   |
| color_gray_luminance | 5/5 :  100% |                                                                                                                                                      |                                   |
| color_desaturate     | 0/5 :  0%   | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br>                  |

# Milestone  transform
Score : 0/15 :  0%
## Detail by Feature
| Feature           | Score     | Missed tests                                                   | Stdout   |
| :---------------- | :-------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| rotate_acw        | 0/3 :  0% | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| mirror_horizontal | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0% | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

