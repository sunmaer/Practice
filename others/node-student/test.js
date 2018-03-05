var mysql = require('mysql');
var connection = mysql.createConnection({
	host: 'localhost',
	user: 'root',
	password: '123456',
	database: 'db_studentmanage'
});

connection.connect();

connection.query('select 1 + 1 as solution', function(error, results, fields) {
	if(error) throw error;
	console.log('The solution is: ', results[0].solution);
});
