make_cat_feature<-function(traindata,testdata)
{
  item_train<-traindata[,1]
  item_train_in_item_cat<-unlist(lapply(item_train,FUN=function(x){which(x==item_cat[,1])}))
  cat_train<-item_cat[item_train_in_item_cat,2]
  cat_level_train<-item_cat[item_train_in_item_cat,3]
  
  unique_cat<-unique(item_cat[,2])
  unique_cat_level<-unique(item_cat[,3])
  
  feature_train<-vector()
  for(i in 1:length(unique_cat)){
    feature_train<-cbind(feature_train,cat_train==unique_cat[i])
  }
  feature_train<-feature_train+0
  
  traindata<-cbind(traindata,feature_train)
  
  item_test<-testdata[,1]
  item_test_in_item_cat<-unlist(lapply(item_test,FUN=function(x){which(x==item_cat[,1])}))
  cat_test<-item_cat[item_test_in_item_cat,2]
  cat_level_test<-item_cat[item_test_in_item_cat,3]
  
  feature_test<-vector()
  for(i in 1:length(unique_cat)){
    feature_test<-cbind(feature_test,cat_test==unique_cat[i])
  }
  feature_test<-feature_test+0
  testdata<-cbind(testdata,feature_test)
  
  
  nname<-1:ncol(traindata)
  cname<-unlist(lapply(nname,FUN=function(x){paste('V',x,sep="")}))
  names(traindata)<-cname
  
  nname<-1:ncol(testdata)
  cname<-unlist(lapply(nname,FUN=function(x){paste('V',x,sep="")}))
  names(testdata)<-cname
  
  
  re<-list()
  re$traindata<-traindata
  re$testdata<-testdata
  return(re)
}

make_sub_feature<-function(traindata,testdata)
{
  if(ncol(traindata)!=ncol(testdata)){
    stop("in make_sub_feature")
  }
  p<-ncol(traindata)
  first<-vector()
  second<-vector()
  for(i in 2:(p-1)){
    for(j in (i+1):p){
      first<-c(first,i)
      second<-c(second,j)
    }
    
  }
  subtrainfeature<-abs(traindata[,first]-traindata[,second])
  subtestfeature<-abs(testdata[,first]-testdata[,second])
  
  
  nname<-1:ncol(subtrainfeature)
  cname<-unlist(lapply(nname,FUN=function(x){paste('SUB',x,sep="")}))
  names(subtrainfeature)<-cname
  names(subtestfeature)<-cname
  
  re<-list()
  re$subtrainfeature<-subtrainfeature
  re$subtestfeature<-subtestfeature
  return(re)

}