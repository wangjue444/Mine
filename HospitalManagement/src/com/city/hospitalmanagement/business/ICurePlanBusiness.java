package com.city.hospitalmanagement.business;

import java.util.List;

import com.city.hospitalmanagement.value.CurePlanValue;



public interface ICurePlanBusiness {
	public List<CurePlanValue> getList() throws Exception;
	public void add(String time,String event,String howoften,String details,int patientid) throws Exception;
	public void delete(int planid) throws Exception;
	public CurePlanValue get(int planid) throws Exception;
	public void update(int planid,String time,String event,String howoften,String details,int patientid) throws Exception;
	public List<CurePlanValue> select(int patientid) throws Exception;
}
