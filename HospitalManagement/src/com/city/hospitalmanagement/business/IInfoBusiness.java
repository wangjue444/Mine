package com.city.hospitalmanagement.business;

import java.util.List;

import com.city.hospitalmanagement.value.InfoValue;

public interface IInfoBusiness {
	public List<InfoValue> getList() throws Exception;
	public void add(String name,int age,String tel,String othertel,String diseasetype,String photo) throws Exception;
	public void delete(int id) throws Exception;
	public InfoValue get(int id) throws Exception;
	public void update(int id,String name,int age,String tel,String othertel,String diseasetype) throws Exception;
	public InfoValue getMax() throws Exception;
}
