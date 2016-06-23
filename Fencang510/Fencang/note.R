subtrain<-subfeature(traindata,c(18,22))
subtest<-subfeature(testdata,c(18,22))

subtrain<-traindata[,c("Group.1","V7","V8","V9","V10","V11","V12","V14","V15","V17","V18","V19","V20","V21","V22","V24","V25","V26","V28")]
subtest<-testdata[,c("Group.1","V7","V8","V9","V10","V11","V12","V14","V15","V17","V18","V19","V20","V21","V22","V24","V25","V26","V28")]
subtrain<-traindata[,c(1,2,3,4,5,6,7,9,10,12,13,14,15,16,17,19,20,21,23)]
subtest<-testdata[,c(1,2,3,4,5,6,7,9,10,12,13,14,15,16,17,19,20,21,23)]
subtest<-testdata[,c("Group.1","V7","V8","V9","V10","V11","V12","V14","V15","V17","V18","V19","V20","V21","V22","V24","V25","V26","V28")]
rf<-rfmode(subtrain,trainy)
pr<-rfpre(rf,subtest)
cost<-costvalue(pr,testy,testdata,config2,0)


names(traindata)<-c("item_id","pv_ipv","pv_uv","cart_ipv","cart_uv","collect_uv","num_gmv","amt_gmv","qty_gmv","unum_gmv","amt_alipay","num_alipay","qty_alipay","unum_alipay","ztc_pv_ipv","tbk_pv_ipv","ss_pv_ipv","jhs_pv_ipv","ztc_pv_uv","tbk_pv_uv","ss_pv_uv","jhs_pv_uv","num_alipay_njhs","amt_alipay_njhs","qty_alipay_njhs","unum_alipay_njhs")

names(traindata)<-c("date","item_id","cate_id","cate_level_id","brand_id","supplier_id","pv_ipv","pv_uv","cart_ipv","cart_uv","collect_uv","num_gmv","amt_gmv","qty_gmv","unum_gmv","amt_alipay","num_alipay","qty_alipay","unum_alipay","ztc_pv_ipv","tbk_pv_ipv","ss_pv_ipv","jhs_pv_ipv","ztc_pv_uv","tbk_pv_uv","ss_pv_uv","jhs_pv_uv","num_alipay_njhs","amt_alipay_njhs","qty_alipay_njhs","unum_alipay_njhs")



date����
item_id��ƷID
cate_idҶ����ĿID
cate_level_id����ĿID
brand_idƷ��ID
supplier_id��Ӧ��ID
pv_ipv �������
pv_uv ����UV
cart_ipv���ӹ�����
cart_uv�ӹ��˴�
collect_uv�ղؼ��˴�
num_gmv���±���
amt_gmv���½��
qty_gmv���¼���
unum_gmv����UV
amt_alipay�ɽ����
num_alipay�ɽ�����
qty_alipay�ɽ�����
unum_alipay�ɽ��˴�
ztc_pv_ipvֱͨ�������������
tbk_pv_ipv�Ա��������������
ss_pv_ipv���������������
jhs_pv_ipv�ۻ��������������
ztc_pv_uvֱͨ����������˴�
tbk_pv_uv�Ա�����������˴�
ss_pv_uv������������˴�
jhs_pv_uv�ۻ�����������˴�
num_alipay_njhs�Ǿۻ���֧������
amt_alipay_njhs�Ǿۻ���֧�����
qty_alipay_njhs�Ǿۻ���֧������
unum_alipay_njhs�Ǿۻ���֧���˴�


source("FastKNN.R")
distance<-Distance_for_KNN_test(scaletest[,-1], scaletrain[,-1])
pr<-knn_test_function(scaletrain[,-1], distance,trainy, k = 1)


