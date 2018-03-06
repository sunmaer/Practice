var http = require("http");
var url = require("url");
var mysql = require('mysql');

var connection = mysql.createConnection({
	host: 'localhost',
	user: 'root',
	password: '123456',
	database: 'db_studentmanage'
});

function start() {
	function onRequest(request, response) {
		var pathname = url.parse(request.url).pathname;

		response.writeHead(200, {"Content-Type": "text/html; charset='utf8'"});

		var sql;
		if(pathname === "/listUsers") {
			sql = 'SELECT * FROM student';
			// 查询所有数据
			connection.query(sql, function(err, result) {
				if(err) {
					console.log('[SELECT ERROR]-', err.message);
					return;
				}
				response.write(JSON.stringify(result));
				response.end();
			});
			connection.end();
		} else {		
			response.write('hello world');
			response.end();
		}
	}

	http.createServer(onRequest).listen(8888);
	console.log("Server has started.");
}

exports.start = start;
