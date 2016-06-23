package com.city.hospitalmanagement.dao;

import java.util.List;

import com.city.hospitalmanagement.value.InfoValue;

public interface IInfoDao {
	public void create(InfoValue iv) throws Exception;
	public void updtae(InfoValue iv) throws Exception;
	public void delete(InfoValue iv) throws Exception;
	public InfoValue get(int id) throws Exception;
	public List getList() throws Exception;
	public InfoValue getMax() throws Exception;
}
