var express = require('express')
var path = require('path')
var port = process.env.PORT || 3000
var app = express()

app.set('views', './views/pages')
app.set('view engine', 'jade')
app.use(express.bodyParser())
app.use(express.static(path.join(__dirname, 'bower_components')))
app.listen(port)

console.log('movie started on port' + port)

// index.page
app.get('/', function(req, res) {
  res.render('index', {
    title: 'movie 首页',
    movies: [
      {
        title: '机械战警',
        _id: 1,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      },
      {
        title: '机械战警',
        _id: 2,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      },
      {
        title: '机械战警',
        _id: 3,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      },
      {
        title: '机械战警',
        _id: 4,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      },
      {
        title: '机械战警',
        _id: 5,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      },
      {
        title: '机械战警',
        _id: 6,
        poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg'
      }
    ]
  })
})

// detail.page
app.get('/movie/:id', function(req, res) {
  res.render('detail', {
    title: 'movie 详情页',
    movie: {
      doctor: '何塞',
      country: '美国',
      title: '机械战警',
      year: 2014,
      poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg',
      language: '英语',
      flash: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg',
      summary: '哈哈哈哈哈哈哈'
    }
  })
})

// admin.page
app.get('/admin/movie', function(req, res) {
  res.render('admin', {
    title: 'movie 后台录入页',
    movie: {
      title: '',
      doctor: '',
      country: '',
      year: '',
      poster: '',
      flash: '',
      summary: '',
      language: ''
    }
  })
})

// list.page
app.get('/admin/list', function(req, res) {
  res.render('list', {
    title: 'movie 列表页',
    movies: [{
      title: '机械战警',
      _id: 1,
      doctor: '何塞',
      country: '美国',
      year: 2014,
      poster: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg',
      language: '英语',
      flash: 'https://img3.mukewang.com/58533fe900019f3006000338-240-135.jpg',
      summary: '哈哈哈哈哈'
    }]
  })
})