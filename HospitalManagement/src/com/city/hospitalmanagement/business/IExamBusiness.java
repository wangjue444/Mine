package com.city.hospitalmanagement.business;

import java.util.List;

import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.ExamValue;

public interface IExamBusiness {
	public List<ExamValue> getList() throws Exception;
	public void add(int patientid,String time,int breath,int pluse,double temperature,int bloodpressure) throws Exception;
	public void delete(int id) throws Exception;
	public CurePlanValue get(int id) throws Exception;
	public void update(int id,int patientid,String time,int breath,int pluse,double temperature,int bloodpressure) throws Exception;
	public List<ExamValue> select(int patientid) throws Exception;
}
