package com.city.hospitalmanagement.action;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IExamBusiness;
import com.city.hospitalmanagement.business.IPatientHistoryBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;
import com.city.hospitalmanagement.value.ExamValue;
import com.city.hospitalmanagement.value.PatientHistoryValue;

/**
 * Servlet implementation class ToExamMainAction
 */
@WebServlet("/exam/tomain.do")
public class ToExamMainAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ToExamMainAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		IExamBusiness ieb=BusinessFactory.getExamBusiness();
		try{
			List<ExamValue> list=ieb.getList();
			
			request.setAttribute("list", list);
			
			
			RequestDispatcher rd=request.getRequestDispatcher("main.jsp");
			rd.forward(request, response);
			
		}
		catch(Exception e){
			e.printStackTrace();
			String mess=e.getMessage();
			response.sendRedirect("../error.jsp?mess="+mess);
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
