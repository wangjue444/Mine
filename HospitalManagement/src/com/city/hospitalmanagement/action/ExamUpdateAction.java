package com.city.hospitalmanagement.action;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.IExamBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class ExamUpdateAction
 */
@WebServlet("/exam/update.do")
public class ExamUpdateAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ExamUpdateAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		try {
			IExamBusiness ieb=BusinessFactory.getExamBusiness();
			int id=Integer.parseInt(request.getParameter("id"));
			int patientid=Integer.parseInt(request.getParameter("patientid"));
			String time=request.getParameter("time");
			int breath=Integer.parseInt(request.getParameter("breath"));
			int pluse=Integer.parseInt(request.getParameter("pluse"));
			double temperature=Double.parseDouble(request.getParameter("temperature"));
			int bloodpressure=Integer.parseInt(request.getParameter("bloodpressure"));
			ieb.update(id, patientid, time, breath, pluse, temperature, bloodpressure);
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
