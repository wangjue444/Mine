package com.city.hospitalmanagement.business.impl;

import java.util.List;

import com.city.hospitalmanagement.business.IExamBusiness;
import com.city.hospitalmanagement.dao.IExamDao;
import com.city.hospitalmanagement.factory.DaoFactory;
import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.ExamValue;

public class ExamImpl implements IExamBusiness {

	@Override
	public List<ExamValue> getList() throws Exception {
		IExamDao ieo=DaoFactory.getExamDao();
		List<ExamValue> list=ieo.getList();
		return list;
	}

	@Override
	public void add(int patientid, String time, int breath, int pluse,
			double temperature, int bloodpressure) throws Exception {
		IExamDao ieo=DaoFactory.getExamDao();
		ExamValue ev=new ExamValue();
		ev.setPatientid(patientid);
		ev.setTemperature(temperature);
		ev.setTime(time);
		ev.setBloodpressure(bloodpressure);
		ev.setBreath(breath);
		ev.setPluse(pluse);
		ieo.create(ev);

	}

	@Override
	public void delete(int id) throws Exception {
		IExamDao ieo=DaoFactory.getExamDao();
		ExamValue ev=new ExamValue();
		ev.setId(id);
		ieo.delete(ev);
		

	}

	@Override
	public CurePlanValue get(int id) throws Exception {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void update(int id,int patientid, String time, int breath, int pluse,
			double temperature, int bloodpressure) throws Exception {
		IExamDao ieo=DaoFactory.getExamDao();
		ExamValue ev=new ExamValue();
		ev.setId(id);
		ev.setPatientid(patientid);
		ev.setTime(time);
		ev.setBreath(breath);
		ev.setPluse(pluse);
		ev.setTemperature(temperature);
		ev.setBloodpressure(bloodpressure);
		ieo.update(ev);
		

	}

	@Override
	public List<ExamValue> select(int patientid) throws Exception {
		IExamDao ieo=DaoFactory.getExamDao();
		List<ExamValue> list=ieo.select(patientid);
		return list;
	}

}
