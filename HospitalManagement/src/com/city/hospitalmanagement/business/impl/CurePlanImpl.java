package com.city.hospitalmanagement.business.impl;

import java.util.List;

import com.city.hospitalmanagement.business.ICurePlanBusiness;
import com.city.hospitalmanagement.dao.ICurePlanDao;
import com.city.hospitalmanagement.dao.IInfoDao;
import com.city.hospitalmanagement.factory.DaoFactory;
import com.city.hospitalmanagement.value.CurePlanValue;
import com.city.hospitalmanagement.value.InfoValue;

public class CurePlanImpl implements ICurePlanBusiness {

	@Override
	public List<CurePlanValue> getList() throws Exception {
		List<CurePlanValue> list;
		ICurePlanDao cpo=DaoFactory.getCurePlanDao();
		list=cpo.getList();
		return list;
	}

	

	@Override
	public void delete(int planid) throws Exception {
		CurePlanValue cv=new CurePlanValue();
		cv.setPlanid(planid);
		ICurePlanDao cpo=DaoFactory.getCurePlanDao();
		cpo.delete(cv);

	}

	@Override
	public CurePlanValue get(int planid) throws Exception {
		// TODO Auto-generated method stub
		return null;
	}



	@Override
	public void add(String time, String event, String howoften, String details,
			int patientid) throws Exception {
		ICurePlanDao cpo=DaoFactory.getCurePlanDao();
		CurePlanValue cv=new CurePlanValue();
		cv.setDetails(details);
		cv.setEvent(event);
		cv.setHowoften(howoften);
		cv.setPatientid(patientid);
		cv.setTime(time);
		cpo.create(cv);
		
		
	}



	@Override
	public void update(int planid,String time, String event, String howoften,
			String details, int patientid) throws Exception {
		ICurePlanDao cpo=DaoFactory.getCurePlanDao();
		CurePlanValue cv=new CurePlanValue();
		cv.setPlanid(planid);
		cv.setTime(time);
		cv.setEvent(event);
		cv.setHowoften(howoften);
		cv.setDetails(details);
		cv.setPatientid(patientid);
		cpo.update(cv);
		
		
	}



	@Override
	public List<CurePlanValue> select(int patientid) throws Exception {
		List<CurePlanValue> list;
		ICurePlanDao cpo=DaoFactory.getCurePlanDao();
		list=cpo.select(patientid);
		return list;
	}



}
