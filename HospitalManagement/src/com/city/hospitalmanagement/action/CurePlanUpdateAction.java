package com.city.hospitalmanagement.action;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.city.hospitalmanagement.business.ICurePlanBusiness;
import com.city.hospitalmanagement.factory.BusinessFactory;

/**
 * Servlet implementation class CurePlanUpdateAction
 */
@WebServlet("/cureplan/update.do")
public class CurePlanUpdateAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CurePlanUpdateAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		 try {
			 int planid=Integer.parseInt(request.getParameter("planid"));
			 String time=request.getParameter("time");
			 String event=request.getParameter("event");
			 String howoften=request.getParameter("howoften");
			 String details=request.getParameter("details");
			 int patientid=Integer.parseInt(request.getParameter("patientid"));
			 ICurePlanBusiness cpb=BusinessFactory.getCurePlanBusiness();
			cpb.update(planid,time, event, howoften, details, patientid);
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
