package com.city.hospitalmanagement.business.impl;

import java.util.ArrayList;
import java.util.List;

import com.city.hospitalmanagement.business.IInfoBusiness;
import com.city.hospitalmanagement.dao.IInfoDao;
import com.city.hospitalmanagement.factory.DaoFactory;
import com.city.hospitalmanagement.value.InfoValue;

public class InfoImpl implements IInfoBusiness {

	@Override
	public List<InfoValue> getList() throws Exception{
		
		List<InfoValue> list;
		IInfoDao ido=DaoFactory.getInfoDao();
		list=ido.getList();
		return list;
		
	}

	@Override
	public void add(String name, int age, String tel, String othertel,String diseasetype,String photo) throws Exception {
		IInfoDao ido=DaoFactory.getInfoDao();
		InfoValue iv=new InfoValue();
		iv.setName(name);
		iv.setAge(age);
		iv.setTel(tel);
		iv.setOthertel(othertel);
		iv.setDiseasetype(diseasetype);
		iv.setPhoto(photo);
		ido.create(iv);
		
	}

	@Override
	public void delete(int id) throws Exception {
		
		IInfoDao ido=DaoFactory.getInfoDao();
		InfoValue iv=new InfoValue();
		iv.setId(id);
		ido.delete(iv);
	}

	@Override
	public InfoValue get(int id) throws Exception {
		IInfoDao ido=DaoFactory.getInfoDao();
		InfoValue iv=ido.get(id);
		return iv;
	}

	@Override
	public void update(int id, String name, int age, String tel,String othertel, String diseasetype) throws Exception {
		IInfoDao ido=DaoFactory.getInfoDao();
		InfoValue iv=new InfoValue();
		iv.setAge(age);
		iv.setId(id);
		iv.setName(name);
		iv.setTel(tel);
		iv.setOthertel(othertel);
		iv.setDiseasetype(diseasetype);
		ido.updtae(iv);
		
	}

	@Override
	public InfoValue getMax() throws Exception {
		IInfoDao ido=DaoFactory.getInfoDao();
		InfoValue iv=ido.getMax();
		return iv;
	}

}
