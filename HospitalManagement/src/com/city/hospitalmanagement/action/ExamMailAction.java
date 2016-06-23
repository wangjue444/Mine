package com.city.hospitalmanagement.action;

import java.io.IOException;
import java.util.List;
import java.util.Properties;

import javax.mail.Message;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.city.hospitalmanagement.value.ExamValue;

/**
 * Servlet implementation class ExamMailAction
 */
@WebServlet("/exam/mail.do")
public class ExamMailAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ExamMailAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession se=request.getSession();
		
		String mail=request.getParameter("mail");
		List<ExamValue> list=(List<ExamValue>)se.getAttribute("list");
		
		
		
		try{
		
		Properties p=new Properties();
		p.put("mail.smtp.host", "smtp.qq.com");
		p.put("mail.transport.protocol","smtp");
		p.put("mail.smtp.auth", "true");
		MailAuth auth=new MailAuth("446944682@qq.com","8058226riseagain");
		Session session=Session.getDefaultInstance(p,auth);
		
		Message message=new MimeMessage(session);
		
		message.setFrom(new InternetAddress("446944682@qq.com"));
		message.setRecipient(Message.RecipientType.TO, new InternetAddress(mail));
		message.setSubject("体检记录");
		
		String content="";
		for(int i=0;i<list.size();i++){
			content=content+"编号："+list.get(i).getId()+" 病人编号:"+list.get(i).getPatientid()+" 时间:"+list.get(i).getTime()+" 血压:"+list.get(i).getBloodpressure()+" 呼吸:"+list.get(i).getBreath()+" 脉搏:"+list.get(i).getPluse()+" 体温:"+list.get(i).getTemperature()+"\n";
			
		}
		
		message.setText(content);
		Transport.send(message);
		
		response.sendRedirect("ok.jsp");
		return;
		
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
