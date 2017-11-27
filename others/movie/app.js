var express = require('express')
var path = require('path')
var port = process.env.PORT || 3000
var bodyParser = require('body-parser')
var app = express()

app.set('views', './views/pages')
app.set('view engine', 'jade')
app.use(bodyParser.urlencoded({ extended: false }))
app.use(express.static(path.join(__dirname, 'bower_components')))
app.listen(port)

console.log('movie started on port' + port)

// index.page
app.get('/', function(req, res) {
  res.render('index', {
    title: '首页',
    movies: [
      {
        title: '军师联盟',
        _id: 1,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      },
      {
        title: '军师联盟',
        _id: 2,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      },
      {
        title: '军师联盟',
        _id: 3,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      },
      {
        title: '军师联盟',
        _id: 4,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      },
      {
        title: '军师联盟',
        _id: 5,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      },
      {
        title: '军师联盟',
        _id: 6,
        poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x'
      }
    ]
  })
})

// detail.page
app.get('/movie/:id', function(req, res) {
  res.render('detail', {
    title: '详情页',
    movie: {
      doctor: '何塞',
      country: '美国',
      title: '机械战警',
      year: 2014,
      poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x',
      language: '英语',
      flash: 'http://player.youku.com/embed/XMzE2MjMwMjgyMA==',
      summary: '哈哈哈哈哈哈哈'
    }
  })
})

// admin.page
app.get('/admin/movie', function(req, res) {
  res.render('admin', {
    title: '后台录入页',
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
    title: '列表页',
    movies: [{
      title: '军师联盟',
      _id: 1,
      doctor: '司马懿',
      country: '中国',
      year: 2014,
      poster: 'https://image.uc.cn/o/wemedia/s/upload/1705232141c868a77c6b40ef11cbab74a449d10dc3;,3,jpegx;3,310x',
      language: '中文',
      flash: 'http://player.youku.com/embed/XMzE2MjMwMjgyMA==',
      summary: '青庐合卺酒，披红骑白马'
    }]
  })
})