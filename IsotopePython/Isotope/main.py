__author__ = 'vinerl'

import numpy as np
import Iso
import ctypes


bb=Iso.Iso("241.csv")
#bb.Search()
x=ctypes.CDLL("share.so")
x.init();
x.explend(24,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
