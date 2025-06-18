# Daily Evaluation 18/06 - 12:43:49
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
Score : 15/26 :  57%
## Detail by Feature
| Feature         | Score      | Missed tests                                                                       | Stdout                            |
| :-------------- | :--------- | :--------------------------------------------------------------------------------- | :-------------------------------- |
| max_pixel       | 3/4 :  75% | Max Pixel black 8x8                                                                | max_pixel (2127188392, 32766): 0… |
| min_pixel       | 0/4 :  0%  | Min Pixel black 8x8<br>Min Pixel white 8x8<br>Min Pixel at 6 5<br>Min Pixel at 3 4 | <br><br><br>                      |
| min_component R | 2/3 :  66% | Min Component R of white 8x8                                                       | min_component R (6, 0): 255       |
| min_component G | 2/3 :  66% | Min Component G of white 8x8                                                       | min_component G (6, 0): 255       |
| min_component B | 2/3 :  66% | Min Component B of white 8x8                                                       | min_component B (6, 0): 255       |
| max_component R | 2/3 :  66% | Max Component R of black 8x8                                                       | max_component R (6, 0): 0         |
| max_component G | 2/3 :  66% | Max Component G of black 8x8                                                       | max_component G (6, 0): 0         |
| max_component B | 2/3 :  66% | Max Component B of black 8x8                                                       | max_component B (6, 0): 0         |

# Milestone  colors
Score : 0/35 :  0%
## Detail by Feature
| Feature              | Score     | Missed tests                                                                                                                                              | Stdout           |
| :------------------- | :-------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 0/5 :  0% | Convert red image to RED<br>Convert blue image to RED<br>Convert green Image to RED<br>Convert white Image to RED<br>convert black Image to RED           | <br><br><br><br> |
| color_blue           | 0/5 :  0% | Convert red image to BLUE<br>Convert blue image to BLUE<br>Convert green Image to BLUE<br>Convert white Image to BLUE<br>convert black Image to BLUE      | <br><br><br><br> |
| color_green          | 0/5 :  0% | Convert red image to GREEN<br>Convert blue image to GREEN<br>Convert green Image to GREEN<br>Convert white Image to GREEN<br>convert black Image to GREEN | <br><br><br><br> |
| color_gray           | 0/5 :  0% | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |
| color_invert         | 0/5 :  0% | Invert red image<br>Invert blue image<br>Invert green Image<br>Invert white Image<br>Invert black Image                                                   | <br><br><br><br> |
| color_gray_luminance | 0/5 :  0% | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |
| color_desaturate     | 0/5 :  0% | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY      | <br><br><br><br> |

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

