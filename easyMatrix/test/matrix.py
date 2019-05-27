#!/usr/bin/env python
# coding=utf-8
import numpy as np
from numpy.linalg import det

m4 = np.array([[1,5,3,5],[5,6,8,1],[9,8,3,1],[4,3,2,7]])
print (det(m4))
