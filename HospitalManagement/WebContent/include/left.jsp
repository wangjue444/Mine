<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>
  <div class="row">
      <div class="span3 bs-docs-sidebar">
	<h1></h1>
	<fmt:setBundle basename="mainText"/>
	<form class="form-horizontal well" action="logout.do">
					 
					<fmt:message key="username"></fmt:message>:${username}<br/>
					 
				 	  

				
					  <fmt:message key="type"/>:${type}<br/>
					
					   <button class="btn btn-warning" type="submit">注销</button>
					
				       
					
									
					</form>
<h1></h1>

        <ul class="nav nav-list bs-docs-sidenav">
          <li><a href="patient/tomain.do"><i class="icon-chevron-right"></i><fmt:message key="patient"/></a></li>
          <li><a href="cureplan/tomain.do"><i class="icon-chevron-right"></i><fmt:message key="cureplan"/> </a></li>
          <li><a href="patienthistory/tomain.do"><i class="icon-chevron-right"></i><fmt:message key="patienthistory"/></a></li>
          <li><a href="exam/tomain.do"><i class="icon-chevron-right"></i><fmt:message key="exam"/></a></li>
      
        </ul>


	       	
	<h1></h1>			
   
   </div>