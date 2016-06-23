package com.city.hospitalmanagement.business;

import java.util.List;

import com.city.hospitalmanagement.value.InfoValue;
import com.city.hospitalmanagement.value.PatientHistoryValue;

public interface IPatientHistoryBusiness {
	public List<PatientHistoryValue> getList() throws Exception;
	public void add(String content,int patientid) throws Exception;
	public void delete(int id) throws Exception;
	public PatientHistoryValue get(int id) throws Exception;
	public void update(int id,String content,int patientid) throws Exception;
	public List<PatientHistoryValue> select(int patientid) throws Exception;
}
