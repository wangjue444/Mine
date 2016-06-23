package com.city.hospitalmanagement.business.impl;

import java.util.List;

import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.dao.ICurePlanDao;
import com.city.hospitalmanagement.dao.IPatientHistoryDao;
import com.city.hospitalmanagement.factory.DaoFactory;
import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.PatientHistoryValue;

public class PatientHistoryImpl implements IPatientHistoryBusiness {

	@Override
	public List<PatientHistoryValue> getList() throws Exception {
		List<PatientHistoryValue> list;
		IPatientHistoryDao phd=DaoFactory.getPatientHistoryDao();
		list=phd.getList();
		return list;
	}

	@Override
	public void add( String content, int patientid) throws Exception {
		IPatientHistoryDao phd=DaoFactory.getPatientHistoryDao();
		PatientHistoryValue pv=new PatientHistoryValue();
		pv.setContent(content);
		
		pv.setPatientid(patientid);
		phd.create(pv);

	}

	@Override
	public void delete(int id) throws Exception {
		IPatientHistoryDao phd=DaoFactory.getPatientHistoryDao();
		PatientHistoryValue pv=new PatientHistoryValue();
		pv.setId(id);
		phd.delete(pv);

	}

	@Override
	public PatientHistoryValue get(int id) throws Exception {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void update(int id, String content, int patientid) throws Exception {
		IPatientHistoryDao phd=DaoFactory.getPatientHistoryDao();
		PatientHistoryValue pv=new PatientHistoryValue();
		pv.setId(id);
		pv.setPatientid(patientid);
		pv.setContent(content);
		phd.update(pv);

	}

	@Override
	public List<PatientHistoryValue> select(int patientid) throws Exception {
		IPatientHistoryDao phd=DaoFactory.getPatientHistoryDao();
		List<PatientHistoryValue> list=phd.select(patientid);
		
		return list;
	}

}
