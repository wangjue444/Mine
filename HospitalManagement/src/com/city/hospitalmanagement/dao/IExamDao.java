package com.city.hospitalmanagement.dao;

import java.util.List;

import com.city.hospitalmanagement.value.ExamValue;

public interface IExamDao {
	public void create(ExamValue ev) throws Exception;
	public void update(ExamValue ev) throws Exception;
	public void delete(ExamValue ev) throws Exception;
	public ExamValue get(int id) throws Exception;
	public List<ExamValue> getList() throws Exception;
	public List<ExamValue> select(int patientid) throws Exception;
}
