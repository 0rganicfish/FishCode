import { request } from './index';
export function getQRKey(params) {
    return request({
        url: '/login/qr/key',
        method: 'get',
        params,
    });
}
