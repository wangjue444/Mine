package com.city.hospitalmanagement.action;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class PatientHistoryUpdateAction
 */
@WebServlet("/patienthistory/update.do")
public class PatientHistoryUpdateAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientHistoryUpdateAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try {
			IPatientHistoryBusiness phb=BusinessFactory.getPatientHistoryBusiness();
			int id=Integer.parseInt(request.getParameter("id"));
			String content=request.getParameter("content");
			int patientid=Integer.parseInt(request.getParameter("patientid"));
			
			phb.update(id, content, patientid);
			
			RequestDispatcher rd=request.getRequestDispatcher("tomain.do");
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
