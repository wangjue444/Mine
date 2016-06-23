package com.city.hospitalmanagement.dao;

import java.util.List;

import com.city.hospitalmanagement.value.CurePlanValue;

public interface ICurePlanDao {
	public void create(CurePlanValue cv) throws Exception;
	public void update(CurePlanValue cv) throws Exception;
	public void delete(CurePlanValue cv) throws Exception;
	public CurePlanValue get(int id) throws Exception;
	public List<CurePlanValue> getList() throws Exception;
	public List<CurePlanValue> select(int patientid) throws Exception;
}
