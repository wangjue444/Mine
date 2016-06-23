package com.city.hospitalmanagement.action;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;
import com.city.hospitalmanagement.value.PatientHistoryValue;

/**
 * Servlet implementation class PatientHistorySelectAction
 */
@WebServlet("/patienthistory/select.do")
public class PatientHistorySelectAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientHistorySelectAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try {
			IPatientHistoryBusiness phb=BusinessFactory.getPatientHistoryBusiness();
			String patientid=request.getParameter("patientid");
			int pid=Integer.parseInt(patientid);
			List<PatientHistoryValue> list=phb.select(pid);
			
			request.setAttribute("list", list);
			RequestDispatcher rd=request.getRequestDispatcher("result.jsp");
			rd.forward(request, response);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
