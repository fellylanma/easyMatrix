#!/usr/bin/env python
# coding=utf-8
import numpy as np
from numpy.linalg import det

m4 = np.array([[1,5,3,5],[5,6,8,1],[9,8,3,1],[4,3,2,7]])
m7 = np.array([
                   [ 1,5,3,5,5,4,3],
                   [ 5,6,8,1,1,6,9],
                   [ 9,8,3,1,2,6,3],
                   [ 4,3,2,7,3,4,5],
                   [ 2,5,7,2,3,5,8],
                   [ 1,2,5,3,7,9,3],
                   [ 9,5,7,9,3,1,5]
])
print (det(m4))
print (det(m7))
