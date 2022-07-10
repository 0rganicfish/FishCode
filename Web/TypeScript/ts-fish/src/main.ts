/*
import { getQRKey } from './api/pa';

const getQRCodeKey = async () => {
  const param = {
    timestamp: new Date().getTime(),
  };
  return getQRKey(param).then(async (res) => {
    if (res.data.code === 200) {
      return res.data.data.unikey;
    }
  });
};

const key = await getQRCodeKey();

console.log(key);

*/

enum httpStatus {
  success = 200,
  nodata = 404,
}

function response(state: number): void {
  switch (state) {
    case httpStatus.success:
      console.log('200! ');
      break;
    case httpStatus.nodata:
      console.log('404');
      break;
    default:
      console.log('err!');
      break;
  }
}

response(404);
