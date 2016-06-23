package com.city.hospitalmanagement.action;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ToExamUpdateAction
 */
@WebServlet("/exam/toupdate.do")
public class ToExamUpdateAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ToExamUpdateAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setAttribute("id",request.getParameter("id"));
		request.setAttribute("patientid",request.getParameter("patientid"));
		request.setAttribute("time",request.getParameter("time"));
		request.setAttribute("breath",request.getParameter("breath"));
		request.setAttribute("pluse",request.getParameter("pluse"));
		request.setAttribute("temperature",request.getParameter("temperature"));
		request.setAttribute("bloodpressure",request.getParameter("bloodpressure"));
		RequestDispatcher rd=request.getRequestDispatcher("update.jsp");
		rd.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
