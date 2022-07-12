const audio = document.querySelector('#audio'),
  cover = document.querySelector('#cover'),
  name = document.querySelector('#name'),
  artist = document.querySelector('#artist'),
  prev = document.querySelector('#prev'),
  next = document.querySelector('#next'),
  play = document.querySelector('#play'),
  container = document.querySelector('.music-footer');

const like = document.querySelector('#like');

let song_index = 0,
  song_length = 0,
  music_list = {};

/**
 * 将秒格式化
 * @returns {string} 00:00 的形式
 */
function formTime(time) {
  const sec = time % 60,
    min = Math.floor(time / 60);

  const fillZero = (num) => {
    const len = num.toString().length;
    return len === 1 ? `0${num}` : `${num}`;
  };
  return `${fillZero(min)}:${fillZero(sec)}`;
}

// 获取歌单
(async () => {
  music_list = await (await fetch('./music.json')).json();
  loadMusic(Math.floor(Math.random() * 6));
  song_length = music_list.music.length;
})();

// 加载音乐
function loadMusic(index) {
  const music = music_list.music[index];
  audio.src = `${music_list.baseUrl}${music.id}`;
  cover.src = `${music.cover}`;
  name.innerHTML = `${music.name}`;
  name.href = `https://music.163.com/#/song?id=${music.id}`;
  artist.innerHTML = `${music.artist}`;
}

//进度条
const progress = document.querySelector('.progressing'),
  curTime = document.querySelector('#now'),
  endTime = document.querySelector('#end');

function update_progress(e) {
  const { duration, currentTime } = e.srcElement;
  progress.style.width = `${(currentTime / duration) * 100}%`;
  curTime.innerHTML = `${formTime(Math.round(currentTime))}`;
  endTime.innerHTML = `${formTime(Math.round(duration))}`;
}

function set_progress(e) {
  const width = this.clientWidth,
    clickX = e.offsetX,
    duration = audio.duration;
  audio.currentTime = (clickX / width) * duration;
}

['canplay', 'timeupdate'].forEach((ele) => {
  audio.addEventListener(ele, update_progress);
});

// 播放、暂停
function play_song() {
  const icon = play.children[0].classList;

  icon.add('fa-pause'), icon.remove('fa-play');
  container.classList.add('play');
  audio.play();
}
function pause_song() {
  const icon = play.children[0].classList;

  icon.remove('fa-pause'), icon.add('fa-play');
  container.classList.remove('play');
  audio.pause();
}

play.addEventListener('click', () => {
  if (container.classList.contains('play')) {
    pause_song();
  } else {
    play_song();
  }
});

// 上下首
prev.addEventListener('click', () => {
  song_index--;
  if (song_index < 0) {
    song_index = song_length - 1;
  }
  loadMusic(song_index), play_song();
});

next.addEventListener('click', () => {
  song_index++;
  if (song_index > song_length - 1) {
    song_index = 0;
  }
  loadMusic(song_index), play_song();
});

//切换like的图标
like.addEventListener('click', () => {
  const list = like.children[0].classList;
  list.toggle('fa-regular'), list.toggle('fa-solid');
});
