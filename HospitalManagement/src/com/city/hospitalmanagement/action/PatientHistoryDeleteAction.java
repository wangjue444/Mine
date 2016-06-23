package com.city.hospitalmanagement.action;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class PatientHistoryDeleteAction
 */
@WebServlet("/patienthistory/delete.do")
public class PatientHistoryDeleteAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public PatientHistoryDeleteAction() {
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
			phb.delete(id);
			response.sendRedirect("tomain.do");
			return;
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
