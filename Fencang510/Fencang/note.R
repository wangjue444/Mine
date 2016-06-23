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



date日期
item_id商品ID
cate_id叶子类目ID
cate_level_id大类目ID
brand_id品牌ID
supplier_id供应商ID
pv_ipv 浏览次数
pv_uv 流量UV
cart_ipv被加购次数
cart_uv加购人次
collect_uv收藏夹人次
num_gmv拍下笔数
amt_gmv拍下金额
qty_gmv拍下件数
unum_gmv拍下UV
amt_alipay成交金额
num_alipay成交笔数
qty_alipay成交件数
unum_alipay成交人次
ztc_pv_ipv直通车引导浏览次数
tbk_pv_ipv淘宝客引导浏览次数
ss_pv_ipv搜索引导浏览次数
jhs_pv_ipv聚划算引导浏览次数
ztc_pv_uv直通车引导浏览人次
tbk_pv_uv淘宝客引导浏览人次
ss_pv_uv搜索引导浏览人次
jhs_pv_uv聚划算引导浏览人次
num_alipay_njhs非聚划算支付笔数
amt_alipay_njhs非聚划算支付金额
qty_alipay_njhs非聚划算支付件数
unum_alipay_njhs非聚划算支付人次


source("FastKNN.R")
distance<-Distance_for_KNN_test(scaletest[,-1], scaletrain[,-1])
pr<-knn_test_function(scaletrain[,-1], distance,trainy, k = 1)



