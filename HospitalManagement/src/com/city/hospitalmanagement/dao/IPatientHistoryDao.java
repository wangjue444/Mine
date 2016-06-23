package com.city.hospitalmanagement.dao;

import java.util.List;

import com.city.hospitalmanagement.value.PatientHistoryValue;

public interface IPatientHistoryDao {
	public void create(PatientHistoryValue pv) throws Exception;
	public void delete(PatientHistoryValue pv) throws Exception;
	public void update(PatientHistoryValue pv) throws Exception;
	public PatientHistoryValue get(int id) throws Exception;
	public List<PatientHistoryValue> getList() throws Exception;
	public List<PatientHistoryValue> select(int patientid) throws Exception;
}
