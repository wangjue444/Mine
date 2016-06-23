__author__ = 'vinerl'
import csv
import numpy as np
import random
class Iso:

    convnum=0.001
    A=0.01
    timesofdescent=10
    pdcount=0.0000001
    def __init__(self,filename):
        self.Reader(filename)
        self.bestsos=10000
        self.bestc1=-1
        self.bestc2=-1
        self.bestc3=-1
        self.bestc4=-1
        self.besta1=-1
        self.besta2=-1
        self.besta3=-1
        self.besta4=-1
        self.bestm1=-1
        self.bestm2=-1
        self.bestm3=-1
        self.bestm4=-1
        self.bests1=-1
        self.bests2=-1
        self.bests3=-1
        self.bests4=-1
       # self.com =np.array([[0 for col in range(100)] for row in range(100)])
        self.com=np.zeros((100,100))
        for i in range(0, 100):
            for j in range(0, i+1):
                self.com[i][j] =self.CalCom(i, j)

    def pd(self,new,old):
        return (new-old)/self.pdcount

    def CalCom(self,p1,p2):
        re=1
        for i in range(1,p2+1):
            re=(re*(p1-p2+i))/i
        return re

    def Reader(self,filename):
        reader=csv.reader(open(filename,'r'))
        data=[]
        for iterator in reader:
            for content in iterator:
                data.append(content)

        self.xishu=np.array(data[::-1],dtype=np.float64)
        self.n=len(data)-1

    def Expand(self,c1,a1,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4):
        first=np.zeros(self.n+1)
        second=np.zeros(self.n+1)
        third=np.zeros(self.n+1)
        forth=np.zeros(self.n+1)
        fifth=np.zeros(self.n+1)
        final=np.zeros(self.n+1)


        for i in range(0,self.n+1):
            first[i]=(1-c1-c2-c3-c4)*self.com[self.n][i]*(0.9893**i)*(0.0107**(self.n-i))
        for i in range(0,m1+1):
            second[2*i+s1]=c1*self.com[m1][i]*(a1**i)*((1-a1)**(m1-i))
        for i in range(0,m2+1):
            third[2*i+s2]=c2*self.com[m2][i]*(a2**i)*((1-a2)**(m2-i))
        for i in range(0,m3+1):
            forth[2*i+s3]=c3*self.com[m3][i]*(a3**i)*((1-a3)**(m3-i))
        for i in range(0,m4+1):
            fifth[2*i+s4]=c4*self.com[m4][i]*(a4**i)*((1-a4)**(m4-i))


        for i in range(0,self.n+1):
            final[i]=first[i]+second[i]+third[i]+forth[i]+fifth[i]
        self.expansion=np.array(final)


    def Dis(self):
        return sum((self.xishu-self.expansion)**2)

    def Sos(self,c1,a1,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4):
        self.Expand(c1,a1,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4)
        return self.Dis()

    def Descent(self,m1,s1,m2,s2,m3,s3,m4,s4):

        minsos=10000
        bestc1=-1
        bestc2=-1
        bestc3=-1
        bestc4=-1
        besta1=-1
        besta2=-1
        besta3=-1
        besta4=-1

        for iterator_descent in range(0,self.timesofdescent):
            random.seed(1)
            c1=random.random()
            c2=random.uniform(0,1-c1)
            c3=random.uniform(0,1-c1-c2)
            c4=random.uniform(0,1-c1-c2-c3)
            a1=random.random()
            a2=random.random()
            a3=random.random()
            a4=random.random()
            jishu=0;
            while True:
                jishu=jishu+1
                sos=self.Sos(c1,a1,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4)
                resultexpansion=self.expansion
                c1pd=self.pd(self.Sos(c1+self.pdcount,a1,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                a1pd=self.pd(self.Sos(c1,a1+self.pdcount,c2,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                c2pd=self.pd(self.Sos(c1,a1,c2+self.pdcount,a2,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                a2pd=self.pd(self.Sos(c1,a1,c2,a2+self.pdcount,c3,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                c3pd=self.pd(self.Sos(c1,a1,c2,a2,c3+self.pdcount,a3,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                a3pd=self.pd(self.Sos(c1,a1,c2,a2,c3,a3+self.pdcount,c4,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                c4pd=self.pd(self.Sos(c1,a1,c2,a2,c3,a3,c4+self.pdcount,a4,m1,s1,m2,s2,m3,s3,m4,s4),sos)
                a4pd=self.pd(self.Sos(c1,a1,c2,a2,c3,a3,c4,a4+self.pdcount,m1,s1,m2,s2,m3,s3,m4,s4),sos)


                if (abs(c1pd)<self.convnum and abs(c2pd)<self.convnum and abs(c3pd)<self.convnum and abs(c4pd)<self.convnum and abs(a1pd)<self.convnum and abs(a2pd)<self.convnum and abs(a3pd)<self.convnum and abs(a4pd)<self.convnum) or (c1-self.A*c1pd<0) or (c2-self.A*c2pd<0) or (c3-self.A*c3pd<0) or (c4-self.A*c4pd<0) or (a1-self.A*a1pd<0) or (a2-self.A*a2pd<0) or (a3-self.A*a3pd<0) or (a4-self.A*a4pd<0) or (jishu>10000):
                    if jishu>10000:
                        print("!")

                    print(sos,m1,m2,m3,m4,s1,s2,s3,s4)
                    if (sos<minsos):
                        bestc1=c1
                        bestc2=c2
                        bestc3=c3
                        bestc4=c4
                        besta1=a1
                        besta2=a2
                        besta3=a3
                        besta4=a4
                        minsos=sos
                    break
                else:
                    c1=c1-self.A*c1pd
                    c2=c2-self.A*c2pd
                    c3=c3-self.A*c3pd
                    c4=c4-self.A*c4pd
                    a1=a1-self.A*a1pd
                    a2=a2-self.A*a2pd
                    a3=a3-self.A*a3pd
                    a4=a4-self.A*a4pd

        return minsos,bestc1,besta1,bestc2,besta2,bestc3,besta3,bestc4,besta4

    def Search(self):
        m1=1
        while 2*m1<=self.n:
            m2=1
            while m2<=m1:
                m3=1
                while m3<=m2:
                    m4=1
                    while m4<=m3:
                        s1=0
                        while s1+2*m1<=self.n:
                            s2=s1-1
                            while (s2>=0) and (s2+2*m2<=self.n) and (s2<=s1+1):
                                s3=0
                                while s3+2*m3<=self.n:
                                    s4=s3-1
                                    while (s4>=0) and (s4+2*m4<=self.n) and (s4<=s3+1):
                                        sos,c1,a1,c2,a2,c3,a3,c4,a4=self.Descent(m1,s1,m2,s2,m3,s3,m4,s4)


                                        #print(sos,m1,m2,m3,m4,s1,s2,s3,s4)
                                        if sos<self.bestsos:
                                            self.bestsos=sos
                                            self.bestc1=c1
                                            self.bestc2=c2
                                            self.bestc3=c3
                                            self.bestc4=c4
                                            self.besta1=a1
                                            self.besta2=a2
                                            self.besta3=a3
                                            self.besta4=a4
                                            self.bestm1=m1
                                            self.bestm2=m2
                                            self.bestm3=m3
                                            self.bestm4=m4
                                            self.bests1=s1
                                            self.bests2=s2
                                            self.bests3=s3
                                            self.bests4=s4

                                        s4=s4+1
                                    s3=s3+1
                                s2=s2+1
                            s1=s1+1
                        m4=m4+1
                    m3=m3+1
                m2=m2+1
            m1=m1+1





