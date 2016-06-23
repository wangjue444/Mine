<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 	<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
 	
 	
 	
<!DOCTYPE html>
<html lang="en">
  <head>
	
	<%@ include file="../include/cureplanscript.jsp" %>
  	
    <meta charset="utf-8">
    <title>Base · Bootstrap</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content=""> 

    <!-- Le styles -->
    <link href="../assets/css/bootstrap.css" rel="stylesheet">
    <link href="../assets/css/bootstrap-responsive.css" rel="stylesheet">
    <link href="../assets/css/docs.css" rel="stylesheet">
    <link href="../assets/js/google-code-prettify/prettify.css" rel="stylesheet">

    <!-- Le HTML5 shim, for IE6-8 support of HTML5 elements -->
    <!--[if lt IE 9]>
      <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->

    <!-- Le fav and touch icons -->
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="../assets/ico/apple-touch-icon-144-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="../assets/ico/apple-touch-icon-114-precomposed.png">
      <link rel="apple-touch-icon-precomposed" sizes="72x72" href="../assets/ico/apple-touch-icon-72-precomposed.png">
                    <link rel="apple-touch-icon-precomposed" href="../assets/ico/apple-touch-icon-57-precomposed.png">
                                   <link rel="shortcut icon" href="../assets/ico/favicon.png">
   

  </head>

  <body data-spy="scroll" data-target=".bs-docs-sidebar">

    
<jsp:include page="../include/top.jsp"/>

  <div class="container">

    <!-- Docs nav
    ================================================== -->
  		<jsp:include page="../include/cureplanleft.jsp"></jsp:include>
      
      <div class="span9">
      		<table id="maintable" class="table table-hover">
      			<thead>
      			
      			<tr>
      			
      				<th>医治计划编号</th>
      				<th>时间</th>
      				<th>事件</th>
      				<th>频率</th>
      				<th>详细</th>
      				
      				<th>病人编号</th>
      			</tr>
      			</thead>
      			<tbody>
      			    <c:forEach var="cureplan" items="${list}">
      			    
      			    <tr>
      			    	<td>${cureplan.planid}</td>
      			    	<td>${cureplan.time}</td>
      			    	<td>${cureplan.event}</td>
      			    	<td>${cureplan.howoften}</td>
      			    	<td>${cureplan.details}</td>
      			    
      			    	<td>${cureplan.patientid}</td>
      			    </tr>
      			
      			    </c:forEach>
      			    
      			</tbody>
      		</table>
       
        	<form id="form" name="form" hidden="true" method="post">
        		<input type="text" id="planid" name="planid"/>
        		<input type="text" id="time" name="time"/>
        		<input type="text" id="event" name="event"/>
        		<input type="text" id="howoften" name="howoften"/>
        		<input type="text" id="details" name="details"/>
        		
        		<input type="text" id="patientid" name="patientid"/>
        	</form>

    </div>

  </div>



    <!-- Footer
    ================================================== -->
   

<jsp:include page="../include/footer.jsp"></jsp:include>

    
	
	 

  </body>
</html>